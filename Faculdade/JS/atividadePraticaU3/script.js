
//Definindo as regras.
const regras = {
    Pedra: 'Tesoura', //Jogador que escolher pedra, ganha.
    Papel: 'Pedra', //Jogador que escolher papel, ganha.
    Tesoura: 'Papel' //Jogador que escolher tesoura, ganha. 
};


//Função para receber os valores
function definirValor(escolhajogador){
    //Criando a jogada das maquinas
    const opcoes = ['Papel', 'Tesoura', 'Pedra'];
    const escolhaMaquina = opcoes[Math.floor(Math.random()* 3)];

    //Alterando a interface
    document.querySelector('.jogador').innerHTML = `Você escolheu: <span class="negrito">${escolhajogador} </span>`;
    document.querySelector('.maquina').innerHTML = `A Maquina Escolheu: <span class="negrito">${escolhaMaquina}</span>`;

    //Mostrar o resultado de acordo com o jogo.
    const carregandoDiv = document.querySelector('.carregando');
    const resultado = verificarResultado(escolhajogador, escolhaMaquina);
    const resultadoDiv = document.querySelector('.resultado');

    //Tempo para esperar 
    setTimeout(() => {
        resultadoDiv.textContent = resultado;
        resultadoDiv.className = 'resultado'; // limpa classes anteriores
        resultadoDiv.removeAttribute('style');

        if (resultado === 'Você venceu!') {
        resultadoDiv.classList.add('vitoria');
        } else if (resultado === 'Você perdeu!') {
        resultadoDiv.classList.add('derrota');
        } else {
        resultadoDiv.classList.add('empate');
        }
        if (resultado !== '') {
        document.getElementById('resetar').style.display = 'block';
        }
        }, 1000);
}



//Função para verificar o resultado.

function verificarResultado(jogador, maquina){
    if (jogador === maquina) {
        return 'Empate';
    }else if (regras[jogador] === maquina) { //Se as regras do jogador, forem iguais a da maquina.
        return 'Você venceu!';
    }else{
        return 'Você perdeu!';
    }    
}

//Função para Resetar

function Resetar(){
  // Elementos
  const jogadorDiv = document.querySelector('.jogador');
  const maquinaDiv = document.querySelector('.maquina');
  const resultadoDiv = document.querySelector('.resultado');

  // Limpa textos
  jogadorDiv.innerHTML = '';
  maquinaDiv.innerHTML = '';
  resultadoDiv.textContent = '';

  // Remove classes e estilos
  resultadoDiv.className = 'resultado';
  resultadoDiv.removeAttribute('style');
  document.body.className = '';
  document.getElementById('resetar').style.display = 'none';
}