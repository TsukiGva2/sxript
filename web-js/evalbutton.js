$(document).ready(function() {
  $("#evalbutton").click(function() {
    var theinput;
    var thecleaninput;
    var theprocessedinput;
    theinput = $("#sxriptin").val();
    thecleaninput = theinput.replace(/^\s+|\s+$/g, "");
    theprocessedinput = thecleaninput;
    document.formsxript.sxriptout.value = sxriptEval("sub({"+theprocessedinput+"})");
    document.formsxript.sxriptout.scrollTop = document.formsxript.sxriptout.scrollHeight;
  });
});

/*$(document).ready(function() {
  $("#sxriptin").keyup(function (e) {
    if ((e.keyCode == 13)) {
      $("#evalbutton").click();
      document.getElementById("sxriptin").select();
    }
  });
});*/
