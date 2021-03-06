'use strict'

var Alexa = require('alexa-sdk');

var flashcardsDictionary = [
  {
    question: 'How do you find the length of a string?',
    rubyAnswer: 'length',
    pythonAnswer: 'len',
    javascriptAnswer: 'length'
  },
  {
    question: 'How do you print to the console or terminal?',
    rubyAnswer: 'puts',
    pythonAnswer: 'print',
    javascriptAnswer:'console.log'
  },
  {
    question:'Are the boolean terms true and false capitalized or lowercase?',
    rubyAnswer: 'lowercase',
    pythonAnswer: 'capitalized',
    javascriptAnswer: 'lowercase'
  }];

var DECK_LENGTH = flashcardsDictionary.length;

var handlers = {

  'LaunchRequest': function(){

    this.attributes['language'] = '';
      this.attributes['numberCorrect'] = 0;
      this.attributes['currentFlashcardIndex'] = 0;

      this.response
          .listen('Tell me your response.').speak(
          'Welcome to Flashcards. In this session, do you want to test' +
          ' your knowledge in Ruby, Python, or Javascript? Which language would you like to practice?');

      this.emit(':responseReady');
  },

  'SetMyLanguageIntent': function(){

    this.attributes['language'] = this.event.request.intent.slots.languages.value;
    var language = this.attributes['language'];

      if (this.attributes['language'] === 'JavaScript') {
        this.attributes['language'] = 'javascript';
      }

      this.response
        .speak('Okay, I will ask you some questions about ' + language + '. Here is your first question. ' + AskQuestion(this.attributes))
        .listen(AskQuestion(this.attributes));

      this.emit(':responseReady');
  },

  'AnswerIntent': function(){

    var userAnswer = this.event.request.intent.slots.answer.value;
    var language = this.attributes['language'];
    var languageAnswer = language + 'Answer';
    var currentFlashcardIndex = this.attributes['currentFlashcardIndex'];
    var correctAnswer = flashcardsDictionary[currentFlashcardIndex][languageAnswer];

    this.attributes['currentFlashcardIndex']++;
    var currentIndex = this.attributes['currentFlashcardIndex'];

    if(userAnswer === correctAnswer){

      this.attributes['numberCorrect']++;
      var numberCorrect = this.attributes['numberCorrect'];
      

      if(currentIndex < DECK_LENGTH){

        this.response.speak('Nice job! The correct answer is ' + correctAnswer + '. You have gotten ' + numberCorrect 
          + ' out of ' + DECK_LENGTH + ' ' +language + ' questions correct. Here is your next question. ' + AskQuestion(this.attributes))
            .listen(AskQuestion(this.attributes));
      }
      else {

        this.response.speak('Nice job! The correct answer is ' + correctAnswer + '. You have gotten ' + numberCorrect 
          + ' out of ' + DECK_LENGTH + ' ' +language + ' questions correct. '+AskQuestion(this.attributes)+
          '. Do you want to play again ').listen('Want to play again?');
      }
    }

    else{

      var numberCorrect = this.attributes['numberCorrect'];
      
      if(currentIndex < DECK_LENGTH){

            this.response.speak('Sorry, the correct answer is ' + correctAnswer + '. You ' +'have gotten ' + numberCorrect 
              + ' out of ' + DECK_LENGTH + ' ' + language + ' questions correct. Here is your next question. ' + 
              AskQuestion(this.attributes))
            .listen(AskQuestion(this.attributes));
          }
          else{

            this.response.speak('Sorry, the correct answer is ' + correctAnswer + '. You ' +'have gotten ' + numberCorrect 
              + ' out of ' + DECK_LENGTH + ' ' + language + ' questions correct. '+AskQuestion(this.attributes)+
              '. Do you want to play again. ').listen('Want to play again?');
          }
    }

    this.emit(':responseReady');
  },

  'PlayAgainIntent': function(){
    this.emit('LaunchRequest');
  },

  'StopGameIntent': function(){
    this.emit('AMAZON.StopIntent');
  },

  'AMAZON.StopIntent': function() {
    this.response.speak('Ok, let\'s play again soon.');
    this.emit(':responseReady');
  
  },

    // Cancel
  ' AMAZON.CancelIntent': function() {
      this.response.speak('Ok, let\'s play again soon.');
      this.emit(':responseReady');
    }

};

// Test my {language} knowledge
var AskQuestion = function(attributes) {

  var language = attributes['language'];
  var currentFlashcardIndex = attributes['currentFlashcardIndex'];

  if (currentFlashcardIndex >= flashcardsDictionary.length) {
    return 'No questions remaining';
  } 
  else {
    var currentQuestion = flashcardsDictionary[currentFlashcardIndex].question;
    return 'In ' + language + ', ' + currentQuestion;
  }

};

exports.handler = function(event, context, callback){

  var alexa = Alexa.handler(event, context, callback);
  alexa.registerHandlers(handlers);
  alexa.execute();

};