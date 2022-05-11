for (let i= 0; i<3; i++)
{
    let btn = document.getElementById("Answer" + string(i));
    btn.addEventListener("click", function onClick() {
        if (btn.innerText === "World Wide Web")
        {
            // change color of box to green
            btn.style.backgroundColor = "green";

        }
        else
        {
            // change color of box to red
        }
    }
    );
}
