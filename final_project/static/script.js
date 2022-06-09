document.addEventListener("DOMContentLoaded", function(){
    // When button is clicked
    let buttons = document.querySelectorAll(".btn-outline-light");
    for (let i = 0; i < buttons.length; i++){
        buttons[i].addEventListener("click", function(){
            window.location.href = '/qs';
            });
        }
    elem = document.querySelector('div.profile-badge');
    elem.style.marginRight = 'auto';
    elem.style.marginLeft = 'auto';
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





