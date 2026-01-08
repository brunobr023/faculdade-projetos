const letras =['A','B','C','D','E','F'].map
    (id => document.getElementById(`letra${id}`));

const table = document.getElementById('table');

table.addEventListener("click", function(event){
    const letra =['A','B','C','D','E','F'].indexOf(event.target.id);
    if(letra !== -1){
        letras[letra].style.backgroundColor = 'rgba(120, 2, 150, 1)';
        letras[letra].focus();
    } else{
        console.warn(`Input para a letra ${event.target.id} não encontrado.`);
    }
    setTimeout(function(){
        event.target.style.visibility = 'hidden';
    }, 500);
});
