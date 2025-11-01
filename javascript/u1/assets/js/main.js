function calcularTabuada(){ 
  //seleciona o elemento input e armazena o valor que o usuario inseriu
  const multiplicador = document.getElementById('multiplicador').value
  const tabuada = document.getElementById('tabuada')
  let resultado
  //condicional para limitar os valores inseridos pelo usuário
  if((multiplicador < 1) || (multiplicador > 10)){
    tabuada.innerHTML = ''
    titulo.innerText = 'O valor deve estar entre 1 e 10!'
  } else {
    //limpa o conteúdo com o resultado anterior, 
    //garantindo que não se emplihem caso o usuário faça várias requisições
    tabuada.innerHTML = ''
    titulo.innerText = `Tabuada do ${multiplicador}:`    
    //calcula e mostra os resultados da tabuada
    for(let index = 1;  index <= 10; index++){
      resultado = index * multiplicador
      const p = document.createElement('p')
      p.innerText = `${multiplicador} X ${index} = ${resultado}`
      tabuada.appendChild(p)
    }
  }
}