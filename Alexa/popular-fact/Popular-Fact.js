"use strict";

var Alexa = require("alexa-sdk");

var user;

var handlers = {
  'LaunchRequest': function() {
    this.response.speak("Hello, Welcome to My academy. Tell me your name").listen("What's your name?");
    this.emit(':responseReady');
  },

  'NameIntent':function(){
    var username = this.event.request.intent.slots.username.value;
    user = username;
    this.response.speak("Hello "+ username +", Tell me what which feild do you like to choose ( Sports or Language) ").listen("Tell me your response");
    this.emit(':responseReady');
  },

  'ResIntent':function(){
    var res = this.event.request.intent.slots.sportandlanguage.value;

    if(res === "sport"){
      this.response.speak("Hello, "+ user+" what do you think is the world's most popular sport?").listen("Tell me what you think is the world's most popular sport.");
    }
    else {
      this.response.speak("Hello, "+user+" Welcome to Mycademy. What do you think is the most popular programming language?").listen("Tell me what you think is Cthe most popular language.");
    }
    this.emit(':responseReady');
  },
  'LanguageIntent': function () {
    var myLanguage = this.event.request.intent.slots.language.value;
    if (myLanguage == "nodejs") {
        this.response.speak("Correct! Nodejs is the most popular language. Do you want to continue or exit").listen("Tell me your response");
    }
    else {
        this.response.speak("You guessed that " + myLanguage + " is the most popular. Actually, Nodejs is the most popular language. Do you want to continue or exit").listen("Tell me your response");
    }
    this.emit(':responseReady');
  },

  'SportIntent': function () {
    var worldSport = this.event.request.intent.slots.sport.value;
    if(worldSport === "football"){
      this.response.speak("Correct! Football is the world's most popular sport. Do you want to continue or exit").listen("Tell me your response");
    }
    else{
      this.response.speak("You guessed that "+ worldSport+" is the most popular. Actually, Football is the world's most popular sport. Do you want to continue or exit").listen("Tell me your response");
    }
    this.emit(':responseReady');
  },

  'ContinueIntent':function(){
    this.response.speak("Ohk "+ user +", Tell me what which feild do you like to choose ( Sports or Language) ").listen("Tell me your response");
    this.emit(':responseReady');
  },

  'CancelIntent':function(){
    this.response.speak("Goodbye!");
    this.emit(':responseReady');
  }

}

exports.handler = function(event, context, callback){
    var alexa = Alexa.handler(event, context);
    alexa.registerHandlers(handlers);
    alexa.execute();
};
