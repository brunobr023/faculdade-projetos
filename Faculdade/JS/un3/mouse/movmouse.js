window.addEventListener('mousemove', (Event) =>{

    const localiza = document.getElementById('position')

    let posicaoX = document.getElementById('posicaoX')
    let posicaoY = document.getElementById('posicaoY')

    localiza.style.top = Event.clientY + 'px'
    localiza.style.left = Event.clientX + (5) + 'px'


    posicaoY.innerText = Event.clientY + 'px'
    posicaoX.innerText = Event.clientX + 'px'
});