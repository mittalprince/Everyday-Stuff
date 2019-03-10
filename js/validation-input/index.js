// Say you have a POST endpoint that accepts the name, email and age parameters:

const express = require('express')
const app = express();

app.use(express.json())

app.post('/form', (req, res) => {
  const name  = req.body.name
  const email = req.body.email
  const age   = req.body.age
})

// You require the check object from the package:

const { check } = require('express-validator/check')

app.post('/form', [
    check('name').isLength({ min: 3 }),
    check('email').isEmail(),
    check('age').isNumeric()
  ], (req, res) => {
    const name  = req.body.name
    const email = req.body.email
    const age   = req.body.age
  })

  // All those checks can be combined by piping them:

  check('name')
  .isAlpha()
  .isLength({ min: 10 })

  // If there is any error, the server automatically sends a response to communicate the error. For example if the email is not valid, this is what will be returned:

//   {
//     "errors": [{
//       "location": "body",
//       "msg": "Invalid value",
//       "param": "email"
//     }]
//   }

  // This default error can be overridden for each check you perform, using withMessage():

  check('name')
  .isAlpha()
  .withMessage('Must be only alphabetical chars')
  .isLength({ min: 10 })
  .withMessage('Must be at least 10 chars long')

  // to write own custom validator

  app.post('/form', [
    check('name').isLength({ min: 3 }),
    check('email').custom(email => {
      if (alreadyHaveEmail(email)) {
        throw new Error('Email already registered')
      }
    }),
    check('age').isNumeric()
  ], (req, res) => {
    const name  = req.body.name
    const email = req.body.email
    const age   = req.body.age
  })

  // From different site 

  router.post('/post', function(req, res) {
    let name = req.body.name;
    let bandwidth = req.body.bandwidth;
  
    req.checkBody('name', 'Name is required').notEmpty();
    req.checkBody('bandwidth', 'Bandwidth is required').notEmpty();
 
    var errors = req.validationErrors();
    if(errors){
       req.session.errors = errors;
       req.session.success = false;
       res.redirect('/blockchain');
    }
    else{
       req.session.success = true;
       res.redirect('/');
    }
 });
 router.get('/', function(req, res){
    res.render('blockchain', { success: req.session.success, errors: req.session.errors });
    req.session.errors = null;
 });
  