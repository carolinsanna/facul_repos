# 🦙 Trabalho da Unidade 2 🦙 

## Proposta

Nesta atividade, você irá criar uma página web que contém uma animação simples utilizando o elemento `<canvas>` do HTML5. A animação consistirá em objetos (por exemplo, círculos)
que se movem ou mudam de cor ao longo do tempo.

## Solução 

```
const canvas = document.getElementById('circle') //Obtém o elemento canvas pelo id
const context = canvas.getContext('2d') //Obtém o contexto de desenho 2D

const circles = [] //Array para armazenar objetos dos círculos

//Gera 20 circulos com posições, velocidades e cores aleatórias
for(let index = 0; index < 20; index++){
  circles.push({
    x: Math.random() * canvas.width, //largura aleatória
    y: Math.random() * canvas.height, //altura aleatória
    rad: 20 + Math.random() * 10, //raio aleatório
    dx: (Math.random() - 0.5) * 4, //velocidade horizontal aleatória
    dy: (Math.random() - 0.5) * 4, //velocidade vertical aleatória
    color: randomColor() //chama a função que gera cores aleatórias
  })
}

//Função para gerar uma cor aleatória
//Retorna uma string com valores rgb() para o atributo color do array de objetos circles
function randomColor() {
  const r = Math.floor(Math.random() * 255) //vermelho
  const g = Math.floor(Math.random() * 255) //verde
  const b = Math.floor(Math.random() * 255) //azul
  return `rgb(${r},${g},${b})`
}

//Função que desenha os círculos dentro do Canvas
//onde c é um objeto dentro de Circles
//x é o atributo para largura deste objeto
//y é a altura deste objeto
//rad é o raio do objeto
function drawCircles(c) {
  context.beginPath() //Começa o caminho
  context.arc(c.x, c.y, c.rad, 0, Math.PI * 2) //Adiciona um círculo no caminho, passando como parametros, os valores gerados aleatoriamente na construção do Array de objetos
  context.fillStyle = c.color //Configura a cor do círculo
  context.fill() //Preenche o círculo
  context.closePath()
}

//Função de atualização 
function update(){
  //Limpa o conteúdo anterior do canvas antes de desenhar o próximo quadro
  //Evita que os círculos deixem rastros no fundo
  context.clearRect(0,0, canvas.width, canvas.height)

  //Percorre os objetos dentro do Array circles
  for (let c of circles){
    //Atualiza a posição dos círculos em cada quadro
    c.x += c.dx //na horizontal
    c.y += c.dy //na vertical

    //Impede que os círculos saiam do Canvas
    //Quando eles tocam as bordas, a velocidade é invertida
    if (c.x + c.rad > canvas.width || c.x - c.rad < 0) c.dx *= -1
    if (c.y + c.rad > canvas.height || c.y - c.rad < 0) c.dy *= -1

    //Desenha o círculo na nova posição
    drawCircles(c)
  }
  //Chama a função de atualizar de novo no próximo quadro da animação
  //Criando um loop contínuo e suave, controlado pelo navegador (+-60fps)
  requestAnimationFrame(update)  
}

//DOM 'ouve' o evento de clique no mouse quando atingir os círculos
//Fazendo com que mudem de cor
canvas.addEventListener('click', e => {
  const rect = canvas.getBoundingClientRect()
  const mouseX = e.clientX - rect.left
  const mouseY = e.clientY - rect.top

  for (let c of circles){
    const dist = Math.hypot(mouseX - c.x, mouseY - c.y)
    if(dist < c.rad){
      c.color = randomColor()
      break
    }
  }
})

update()
```

## Publicação

https://circles-everywhere.netlify.app