
<!--<body onload="pageLoaded();">-->
<script>
$(document).ready (function(){
  pageLoaded();
});
</script>

<div>
  <p>
    *Write some text. Choose the language. Click to see the translation, and then have that translation translated back! See how the Google and Microsoft translators stack up!
  </p>
  <div> 
    <select id="a_from" class="trans"><<option selected="selected" value= "0">Translate from:</option>
      <option value= "ar">Arabic</option><option value= "bg">Bulgarian</option>
      <option value= "ca">Catalan</option><option value= "hr">Croatian</option>
      <option value= "cs">Czech</option><option value= "da">Danish</option>
      <option value= "nl">Dutch</option><option value= "en">English</option>
      <option value= "et">Estonian</option><option value= "fi">Finnish</option>
      <option value= "fr">French</option><option value= "de">German</option>
      <option value= "el">Greek</option><option value= "ht">Haitian Creole</option>
      <option value= "hi">Hindi</option><option value= "hu">Hungarian</option>
      <option value= "id">Indonesian</option><option value= "it">Italian</option>
      <option value= "ko">Korean</option><option value= "lv">Latvian</option>
      <option value= "lt">Lithuanian</option><option value= "ms">Malay</option>
      <option value= "mt">Maltese</option><option value= "no">Norwegian</option>
      <option value= "fa">Persian</option><option value= "pl">Polish</option>
      <option value= "pt">Portuguese</option><option value= "ro">Romanian</option>
      <option value= "ru">Russian</option><option value= "sl">Slovak</option>
      <option value= "sl">Slovenian</option><option value= "es">Spanish</option>
      <option value= "th">Thai</option><option value= "tr">Turkish</option>
      <option value= "uk">Ukrainian</option><option value= "ur">Urdu</option>
      <option value= "vi">Vietnamese</option> </select>
    <select id="a_to" class="trans"><<option selected="selected" value= "0">Translate to:</option>
      <option value= "ar">Arabic</option><option value= "bg">Bulgarian</option>
      <option value= "ca">Catalan</option><option value= "hr">Croatian</option>
      <option value= "cs">Czech</option><option value= "da">Danish</option>
      <option value= "nl">Dutch</option><option value= "en">English</option>
      <option value= "et">Estonian</option><option value= "fi">Finnish</option>
      <option value= "fr">French</option><option value= "de">German</option>
      <option value= "el">Greek</option><option value= "ht">Haitian Creole</option>
      <option value= "hi">Hindi</option><option value= "hu">Hungarian</option>
      <option value= "id">Indonesian</option><option value= "it">Italian</option>
      <option value= "ko">Korean</option><option value= "lv">Latvian</option>
      <option value= "lt">Lithuanian</option><option value= "ms">Malay</option>
      <option value= "mt">Maltese</option><option value= "no">Norwegian</option>
      <option value= "fa">Persian</option><option value= "pl">Polish</option>
      <option value= "pt">Portuguese</option><option value= "ro">Romanian</option>
      <option value= "ru">Russian</option><option value= "sl">Slovak</option>
      <option value= "sl">Slovenian</option><option value= "es">Spanish</option>
      <option value= "th">Thai</option><option value= "tr">Turkish</option>
      <option value= "uk">Ukrainian</option><option value= "ur">Urdu</option>
      <option value= "vi">Vietnamese</option> </select>   
    <button id="translate" class= "button" onclick="translate_back();">Translate All!</button>
  </div>  
  <textarea id= "accuracy_text" placeholder="Typet text to translate!" rows="20" 
    cols="40" class="textarea" role="textbox"></textarea>
  <div id= "g_div"> </div>
  <div id= "m_div"> </div>
</div>










