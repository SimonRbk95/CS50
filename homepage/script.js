document.addEventListener("DOMContentLoaded", function(){
    // When button is clicked
    let buttons = document.querySelectorAll(".button");
    for (let i = 0; i < incorrects.length; i++){
        incorrects[i].addEventListener("click", function(){
            incorrects[i].style.backgroundColor = "red";
            document.getElementById("placeholder1").innerHTML = "incorrect!";
            });
        }
    }