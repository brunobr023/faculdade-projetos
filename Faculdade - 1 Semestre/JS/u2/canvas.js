//iniciando canvas
var canvas = document.getElementById('progress');
var ctx = canvas.getContext('2d');

//configurações
var x = 0;
var y = 0;
var altura = 10;
var largura = 0;
var fator = 60;
var resolucao = 1280;


//cor da barra
ctx.fillStyle = "#4169E1"

// função que anima
function animacao(){
    ctx.fillRect(x, y, largura = largura + fator, altura);
    //interrompe a função setInterval() para evitar carregamento excessivo
    if(largura > resolucao){
        clearInterval(atualiza);
    }
}

//atualizar a barra
var atualiza = setInterval(animacao, 100)