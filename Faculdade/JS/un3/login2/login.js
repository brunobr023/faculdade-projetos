const button = document.querySelector('#button');
const form = document.querySelector('form');

button.addEventListener("click", Event =>{
    Event.preventDefault(); // impede o carregamento da pagina
    form.classList.add('oculta-form');
});

form.addEventListener('animationend', Event =>{
    if(Event.animationName == 'top'){
        form.style.display = 'none';
        window.location.href = 'site.html'
    }
})

//movimento formulário ^

