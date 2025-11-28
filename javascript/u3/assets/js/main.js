const choices = document.querySelectorAll('.choice')
const userChoiceText = document.getElementById('userChoice')
const pcChoiceText = document.getElementById('pcChoice')
const outcomeText = document.getElementById('outcome')
const resetBtn = document.getElementById('reset')

choices.forEach(choice => {
  choice.addEventListener('click', () => {
    const userChoice = choice.dataset.choice
    const pcChoice = getPcChoice()
    const result = checkWinner(userChoice, pcChoice)

    userChoiceText.textContent = 'Você escolheu: ' + userChoice
    pcChoiceText.textContent = 'Máquina escolheu: ' + pcChoice
    outcomeText.textContent = 'Resultado: ' + result
  })
})

function getPcChoice() {
  const options = ['pedra', 'papel', 'tesoura']
  const index = Math.floor(Math.random() * 3)
  return options[index]
}

function checkWinner(user, pc) {
  if (user === pc) return 'Empate!'

  if (
    (user === 'pedra' && pc === 'tesoura') ||
    (user === 'papel' && pc === 'pedra') ||
    (user === 'tesoura' && pc === 'papel')
  ) {
    return 'Você venceu!'
  }

  return 'Máquina venceu!'
}

resetBtn.addEventListener('click', () => {
  userChoiceText.textContent = 'Você escolheu: '
  pcChoiceText.textContent = 'Máquina escolheu: '
  outcomeText.textContent = 'Resultado: '
})

