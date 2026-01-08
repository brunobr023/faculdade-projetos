/*Còdigo para verificar a idade*/

let idade = parseInt(prompt("Digite sua idade"));
let body = document.body;
let mensg = document.getElementById("mensagem");

if (idade >= 18) {
    body.style.background = '#ff2334';
    mensg.style.fontSize = 'xx-large';
    mensg.innerHTML = "Você é maior de 18 anos";
} else {
    body.style.background = '#000000';
    mensg.style.fontSize = 'xx-large';
    mensg.innerHTML = "Você é menor de 18 anos";
}