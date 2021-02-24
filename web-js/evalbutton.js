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
