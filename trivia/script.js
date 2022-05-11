document.addEventListener("DOMContentLoaded", function (){
    // When correct answer is clicked
    let correct = document.getElementById("Answer3");
    correct.addEventListener("click", function (){
        correct.style.backgroundColor = "green";
        document.getElemenById("placeholder1").innerText = "Correct!";
    }
