document.addEventListener("DOMContentLoaded", function(){
    // When button is clicked
    let buttons = document.querySelectorAll(".qs");
    for (let i = 0; i < buttons.length; i++){
        buttons[i].addEventListener("click", function(){
            window.location.href = '/qs';
            });
        }
    let right=document.getElementById('rightdiv').style.height;
    let left=document.getElementById('leftdiv').style.height;
    if(left>right)
    {
        document.getElementById('rightdiv').style.height=left;
    }
    else
    {
        document.getElementById('leftdiv').style.height=right;
    }
});

$('.selectpicker').selectpicker({
   maxOptions: 3,
});

if( /Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent) ) {
  $('.selectpicker').selectpicker('mobile');
}

$('#btnDeselect').on('click',function(){
  $('#select_1').selectpicker('deselectAll');
});

$('#btnDeselect_2').on('click',function(){
    $('#select_2').selectpicker('deselectAll');
});







