const saidaAlt = document.querySelector("#altura");
const saidaLarg = document.querySelector("#largura");

function redimensiona() {
    saidaAlt.textContent = window.innerHeight;
    saidaLarg.textContent = window.innerWidth;
}

// Executa ao carregar a página
redimensiona();

// Atualiza ao redimensionar a janela
window.onresize = redimensiona;
