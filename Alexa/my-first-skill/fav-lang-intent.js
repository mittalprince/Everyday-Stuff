"use strict";

var Alexa = require("alexa-sdk");

var handlers = {
  "HelloIntent": function () {
    this.response.speak("Hello, Prince"); 
    this.emit(':responseReady');
  },
  
  "myFavoriteLanguageIntent": function(){
    this.emit(":tell", "Hello Prince your favorite language is, you know!");
  },
  
  "LaunchRequest": function () {
    this.response.speak("Prince, Welcome to Codecademy"); 
    this.emit(':responseReady');
  },
  'AMAZON.CancelIntent': function() {
    this.response.speak("Ok, Goodbye");
    this.emit(':responseReady');
  }
};

exports.handler = function(event, context, callback){
  var alexa = Alexa.handler(event, context);
    alexa.registerHandlers(handlers);
    alexa.execute();
};