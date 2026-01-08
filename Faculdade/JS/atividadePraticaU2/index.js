// Defininido as variaveis

//Quadrado
let quadrado = document.getElementById('square');
let ctx = quadrado.getContext('2d');

//Circulo
let circulo = document.getElementById('round');
let cct = circulo.getContext('2d');

// Triangulo
let triangulo = document.getElementById('tring');
let tri = triangulo.getContext('2d');


//Renderizando o Quadrado.
ctx.fillRect(45, 45, 100, 100);

//Renderizando o Circulo
cct.beginPath();
cct.arc(100, 75 , 50, 0, 2 * Math.PI);
cct.fill();

//Renderizando o Triangulo
tri.beginPath();
tri.moveTo(75, 25);      // Vértice superior
tri.lineTo(25, 125);     // Vértice inferior esquerdo
tri.lineTo(125, 125);    // Vértice inferior direito
tri.closePath();
tri.fill();

//PARTE 2 DA ATIVIDADE
var start = null;
let progress = 0;
var cir = document.getElementById('cir');
var box = document.getElementById('box');
var tria = document.getElementById('tri');

//Defindo as posições
box.style.position = "relative";
cir.style.position = "relative";
tria.style.position = "relative";


function step(timestamp) {
  if (!start) start = timestamp;
  var progress = timestamp - start;
  //Os 3 Elementos onde há um calculo de progresso. o 1 são os passos e o outro é o limite,
  cir.style.left = Math.min(progress / 10, 500) + "px";
  box.style.left = Math.min(progress / 6, 500) + "px";
  tria.style.left = Math.min(progress / 4, 500) + "px";
  tria.style.transform = `rotate(${progress / 5}deg)`;
  if (progress < 5000) {
    window.requestAnimationFrame(step);
  }
}

window.requestAnimationFrame(step);
