
<!-- <script>
$(document).ready (function(){
  pageLoaded();
});
</script> -->

<div>
  <div> 
    <select id="trans_from" class="trans"><<option selected="selected" value= "0">Translate from:</option>
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
    <select id="trans_to" class="trans"><<option selected="selected" value= "0">Translate to:</option>
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
      <button id="translateButton" class= "button" onclick="translators();">Translate!</button>
  </div>  
  <div> 
    <textarea id= "sourceText" placeholder="Typet text to translate!" rows="20" 
    cols="40" class="textarea" role="textbox"></textarea>
  </div>  
  <div> 
    <div> 
      <img alt="Google Logo" src="/img/google_g_medium.png"/>
    </div>
    <textarea id= "google_translatedText" placeholder="Google's translation will appear here!" rows="20" 
    cols="40" class="textarea" role="textbox"></textarea>
  <div> 
    <div> 
      <img alt="Microsoft's Logo" src="/img/microsoft_logo_medium.png"/>
    </div>
    <textarea id= "microsoft_translatedText" placeholder="Microsoft's translation will appear here!" rows="20" 
    cols="40" class="textarea" role="textbox"></textarea>
  </div>
</div>
*Note that their are often multiple ways to say the same thing in any given language.
<br>










