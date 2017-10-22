/**
 * scripts.js
 *
 * Computer Science 50
 * CS50 Project
 *
 * Global JavaScript.
 */
 
 
/** Global Variables */
// needed because used through multple functions recursively
 
// where translated Google text should go
var g_where;
 
// where translated Microsoft text shuuld go
var m_where;
 
// GoogleTranslation's response
var g_response;
 
// MicrosoftTranslation's repsonse
var m_response;
 
// how should GoogleTranslation's callback be handled
var g_method;
// how should MicrosoftTranslation's callback be handled
var m_method;
// what language to translate from on accuracy page
var a_from;
// what language to translate to on accuracy page
var a_to;
 
 
 
/** CS50 Translate */
 
// CS50 translate home page functionality
function translators () {
  
  // grab text to translate and store it
  var text_input = $("#sourceText").val();
  // grab the "from" language and store it
  var from_lang = $("#trans_from").val();
  // grab the "to" language and store it
  var to_lang = $("#trans_to").val();
  
  // check for user compliance
  // check that a text is provided
  if (text_input == "")
  {
    alert("Please provide text to translate.");
  }
  // check that a "from" language is chosen
  else if (from_lang == "0")
  {
    alert("Please proved a language from which to translate.");
  }
  // check that a "to" language is chosen
  else if (to_lang == "0")
  {
    alert("Please provide a languge to which to translate.");
  }
  // check that the "from" and "to" languages are not the same
  else if (from_lang == to_lang)
  {
    alert("Choose different languages.");
  }
  else
  {
    // set the method of GoogleTranslation's callback
    g_method = 0;
    // set the location of where GoogleTranslation's callback will target
    g_where = $("#google_translatedText");
    
    // set the method of MicrosoftTranslation's callback
    m_method = 0;
    // set the location of where GoogleTranslation's callback will target
    m_where = $("#microsoft_translatedText");
    
    // call GoogeTranslation, which given the g_method will call MicrosoftTranslation with the m_method
    // This is implemented in this fashion so that the call to insert into the
    // history databse is done after both translatiors have gotten back their responses.
    GoogleTranslate(text_input, from_lang, to_lang);
  }
}
 
 
 
/** Translate All (Accuracy) */
 
function translate_back () {
  
  // set location of where GoogleTranslation's callback will target
  g_where = $("#g_div");
  // first empty the div to eliminate duplicates
  g_where.empty();
  // set location of where MicrosoftTranslation's callback will target
  m_where =$("#m_div");
  // fisrt empty the div to aviod duplicates
  m_where.empty();
  // grab text in the textarea box and store it
  var a_text = $("#accuracy_text").val();
  // grab and store the "from" language
  a_from = $("#a_from").val();
  // grab and store the "to" language
  a_to = $("#a_to").val();
  
  // user compliance checking
  // check that some text is provided
  if (a_text == "")
  {
    alert("Please provide text to translate.");
  }
  // check for empty "from" language
  else if (a_from == "0")
  {
    alert("Please proved a language from which to translate.");
  }
  // check for empty "to" language
  else if (a_to == "0")
  {
    alert("Please provide a languge to which to translate.");
  }
  // check that "from" and "to" languages are not the same
  else if (a_from == a_to)
  {
    alert("Choose different languages.");
  }
  // else begin translation
  else
  {
    // append Google's logo to the Google div
    g_where.append("<img alt='Google Logo' src='/img/google_g_medium.png'/><br>");
    // set the method of GoogleTrnaslation's callback
    g_method = 2;
    // call GoogleTranslate
    GoogleTranslate(a_text, a_from, a_to);
    // set the method of MicrosoftTranslation's callback
    m_method = 2;
    // append Microsoft's logo to Microsoft div
    m_where.append("<img alt='Microsoft Logo' src='/img/microsoft_logo_medium.png'/><br>");
    // call MicrosoftTranslate
    MicrosoftTranslate(a_text, a_from, a_to);  
  }
}
 
 
 
 
 
/** Google Scripts */
 
// ajax method of GoogleTranslate (as opposed to the REST which did not work with this implementation)
function GoogleTranslate (text, from, to) {
  // create an object to store values for the ajax call
  var g_object = new Object;
  // set my key to allow for the translation to occur
  g_object.key = "AIzaSyB2IlDkrsPX3Sy-4bPs9LMkPlCLLn9ZtFg";
  // set the "from" language
  g_object.source = from;
  // set the "to" language
  g_object.target = to;
  // set the text to be translated
  g_object.q = text;
  // ajax call
  $.ajax({
    // set the type
    type: "GET",
    // set the url
    url: "https://www.googleapis.com/language/translate/v2",
    // set what data to pass the call
    data: g_object,
    // set the datatype
    dataType: 'jsonp',
    // when the call is successfull
    success: function (response) {
      // set GoogleTranslation's response
      g_response = response.data.translations[0].translatedText;
      // check if g_method is 0
      if (g_method == 0)
      {
        // replace the text in the given g_where with GooogleTranslation's response
        g_where.val(g_response);
        
        // call MicrosoftTranslation
        MicrosoftTranslate(text, from, to);
        
      }
      // check for g_method of 1
      if (g_method == 1)
      {
        // append the translattion of the translate text to the Google div in bold
        g_where.append("<br>- and back -<br><strong>" + g_response + "</strong><br><br>");
      }
      // check for g_method 2
      if (g_method == 2)
      {
        // append Google's response in bold to the Google div
        g_where.append("<strong>" + g_response + "</strong>");
        // set method to 1
        g_method = 1;
        // call GoogleTranslate to have the first response translated back to the original "from" language
        GoogleTranslate(g_response, a_to, a_from);
      }
    },
    // when the call fails
    error: function (response) {
      // allert with why the response failed
      alert('Error:' + response.error.message);
    }
  });
  }
 
 
 
 
/** Microsoft Scripts */
 
// crreat global variale to store current token for MicrosoftTranslate to work
var global_token = '';
 
// grab a token or renew it when needed
function pageLoaded() {
  // obtain access token (usuable for 10 minutes)
  getToken();
  
  // get a token every 9 minutes just to be sure
  setInterval(getToken, 9 * 60 * 1000);
}
 
 
// function and ajax call to get token
function getToken() {
  // store the the url
  var str = "./token.php";
  // calll ajax
  $.ajax({
    // set the type of call
    type: "POST",
    // set url
    url: str,
    // set cache to true
    cache: true,
    // set the datatype
    dataType: 'json',
    // on success set the global token to be used by MicrosoftTranslate
    success: function (data) {
      global_token = data
    }
  });
}
 
 
// microsoft translate
function MicrosoftTranslate(text, from, to, where) {
  
  // create object to store values passed to ajax call
  var m_object = new Object;
  // set the text to translate
  m_object.text = text;
  // set the "from" language
  m_object.from = from;
  // set the "tp" language
  m_object.to = to;
  // *for a different implementation of MicrosoftTranslate: m_object.oncomplete = "microsoft_translation";
  // set value for MicrosoftTranslate to use my account 
  m_object.appId = "Bearer " + global_token;
  /// store the url
  var requestStr = "https://api.microsofttranslator.com/V2/Ajax.svc/Translate";
  // set the ajax call to a variable to have the ability of a .done function
  var request = $.ajax({
    
    // set the type of call
    type: "GET",
    // set the url
    url: requestStr,
    // set the data passed through
    data: m_object,
    // set the data type
    dataType: 'jsonp',
    // make sure there is an oncomplete for MicrosoftTranslate to work with .done
    jsonp: 'oncomplete',
    // set cache to true
    cache: true,
  });
  
  // when the ajax call is done
  request.done(function(response) {
  // set the m_response to the response of the ajax call, MicrosoftTranslate's translated text
  m_response = response;
  // check for m_method of 0
  if (m_method == 0)
  {
    // replace the value in the given m_where
    m_where.val(m_response);
    // ajax call to store history into SQL database
    $.ajax({
      // set the type
      type: "POST",
      // set the url
      url: "https://ide50-meritonibrahimi.cs50.io/history.php",
      // set the data passed to it
      data:{  sourcetext: text, 
              // grab the text value (the actual language and not the code) of the "from" language
              from_lang: $("#trans_from option[value=" + from + "]").text(),
              // grab the text value (the actual language and not the code) of the "to" language
              to_lang: $("#trans_to option[value=" + to + "]").text(),
              // pass Google's response
              google: g_response,
              // pass Microsoft's response
              microsoft: m_response
      },
      // have an on success for the call to work
      success: function(data) {}
    });
  }
  // check for a m_method of 1
  if (m_method == 1)
  {
    // append the given m_where location with the translattion of the translate text in bold
    m_where.append("<br>- and back -<br><strong>" + m_response + "</strong><br><br>");
    // create a new div to hold a message
    var newdiv = "<div id= 'div1'></div>";
    // set the m_where where the new div will be placed
    m_where = $("#m_div");
    // append the new div to the Microsoft div
    m_where.append(newdiv);
    // set the new div to the m_where
    m_where = $("#div1");
    // append to the div this message
    m_where.append("Try different combinations of text and languages to see how well the translators work!");
  }
  // check for a m_method of 3
  if (m_method == 2)
  {
    // append to the given m_where location the response of MicrosoftTranslate in bold
    m_where.append("<strong>" + m_response + "</strong>");
    // set the m_method to 1
    m_method = 1;
    // call MicrosoftTranslate to have the first response translated back to the original "from" language
    MicrosoftTranslate(m_response, a_to, a_from);
  }    
  });
  
  // on fail of the MicrosoftTranslate ajax call
  request.fail(function() {
    alert("Microsoft Translator experienced difficulty. Try again later!");
  });
}