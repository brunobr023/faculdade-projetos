function Solicitacao (){
    //Criando um objeto
    const xhr = new XMLHttpRequest();

    //Solicitando acesso a API, O metodo.
    xhr.open('GET','https://raw.githubusercontent.com/mdn/content/main/files/en-us/_wikihistory.json', true);

    xhr.onload = function(){
        if (xhr.status === 200) {
        // Funcionou a conexão
         const response = JSON.parse(xhr.responseText);
         console.log("Informação: ", response.Games.contributors);
        }else{
            //falhou
            console.log("Erro", xhr.status);
        }
    };
    // Envia a solciticação
    xhr.send()


}