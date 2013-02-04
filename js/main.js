//$(window).load(function() {
//	$('#slider').nivoSlider();
//});



//$(function() {
//	$("ul.tabs").tabs("#gallery > .content >  ul.gallery_group", {effect: 'fade', fadeSpeed: 400});
//});



$(document).ready(function() {	
    $("a.image").fancybox();

    SyntaxHighlighter.autoloader(
      "bash                      sh/scripts/shBrushBash.js"
      ,"css                      sh/scripts/shBrushCss.js"
      ,"c cpp                    sh/scripts/shBrushCpp.js"
      ,"php                      sh/scripts/shBrushPhp.js"
      ,"diff                     sh/scripts/shBrushDiff.js"
      ,"html xml xhtml           sh/scripts/shBrushXml.js"
      ,"js jscript javascript    sh/scripts/shBrushJScript.js"
      ,"perl pl                  sh/scripts/shBrushPerl.js"
      ,"plain                    sh/scripts/shBrushPlain.js"
      ,"python py                sh/scripts/shBrushPython.js"
      ,"sql                      sh/scripts/shBrushSql.js"
      ,"tt tt2                   sh/scripts/shBrushTT2.js"
      ,"yaml yml                 sh/scripts/shBrushYAML.js"
    );

    SyntaxHighlighter.all();

});
