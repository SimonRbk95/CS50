document.addEventListener("DOMContentLoaded", function(){
    // When button is clicked
    let buttons = document.querySelectorAll(".btn-outline-light");
    for (let i = 0; i < buttons.length; i++){
        buttons[i].addEventListener("click", function(){
            window.location.href = 'application.html';
            });
        }
    });

// asynchronously load the images before the carousel tries itsel
let img = new Image(),
url = "background_1.1.png",
container = document.getElementById("img-holder-1");
img.onload = function () { container.appendChild(img); };
img.src = url;

let img_2 = new Image(),
url_2 = "background_3.1.png",
container_2 = document.getElementById("img-holder-2");
img_2.onload = function () { container_2.appendChild(img_2); };
img_2.src = url_2;