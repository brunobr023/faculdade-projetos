// Laço de repetição para gerar os mapas

let turismo = [["Hamilton, Canadá", 43.255203, -79.843826],["Gramado, Brasil", -29.37463, -50.87402]];
for(i=0; i < turismo.length; i++){
    var map = new ol.Map({
        target: 'local-'+(i+1),
        layers: [
            new ol.layer.Tile({
                source: new ol.source.OSM()
            })
        ],
        view: new ol.View({
            center: ol.proj.fromLonLat([
                turismo[i][2],
                turismo[i][1]
            ]),
            zoom: parseInt(prompt("Zoom desejado [Entre 5 a 15]: ")),
        })
    });
}