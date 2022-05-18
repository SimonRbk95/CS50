document.addEventListener("DOMContentLoaded", function(){
    // When button is clicked
    let buttons = document.querySelectorAll(".btn-outline-light");
    for (let i = 0; i < buttons.length; i++){
        buttons[i].addEventListener("click", function(){
            window.location.href = 'application.html';
            });
        }
    });

let img = new Image(),
url = "background_2.1.png",
container = document.getElementById("img-holder-1");

img.onload = function () { container.appendChild(img); };
img.src = url;