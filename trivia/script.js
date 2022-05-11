
let btn1 = document.getElementById("Answer1");
let btn2 = document.getElementById("Answer2");
let btn3 = document.getElementById("Answer3");
let btn4 = document.getElementById("Answer4");


document.addEventListener("DOMContentLoaded", function (){
    // When correct answer is clicked
    let correct = document.getElementById("Answer3");
    correct.addEventListener("click", function (){
        correct.style.backgroundColor = "green";
        
    }
    ]
})

while (true)
{
    checkAnswer(btn1);
    checkAnswer(btn2);
    checkAnswer(btn3);
    checkAnswer(btn4);
}






function checkAnswer(btnX)
{
    btnX.addEventListener("click", function onClick()
    {
        if (btnX.innerText === "World Wide Web")
        {
            // change color of box to green
            btnX.style.backgroundColor = "green";

        }
        else
        {
            // change color of box to red
            btnX.style.backgroundColor = "red";
        }
    });
}
