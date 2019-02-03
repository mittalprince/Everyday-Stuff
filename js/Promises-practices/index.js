/*  Links

https://scotch.io/tutorials/javascript-promises-for-dummies

*/

// prototype new Promise( (resolve, reject) => { })
// in (resolve, reject) function write the code and call reject with response in true condition else reject with err
// then always with promise
//then handle successful resolve function with resp
// catch handle reject case

var isMomHappy = true;

var willIgetphone = new Promise(
    function(resolve, reject){
        if(isMomHappy){
            var phone = {
                brand: 'Samsung',
                color: 'black'
            }
            resolve(phone);
        } else{
            var reason = "Mom not happy";
            reject(reason);
        }
    }
)

// simple promise example
var askMon = function(){
    willIgetphone
    .then( function(fullfilled){
        console.log(fullfilled)
    })
    .catch( function(reason){
        console.log(reason);
    })
}

askMon();

var showOff = function(phone){
    return new Promise(
        function(resolve, reject){
            var message = 'Hey i have ' + phone;
            resolve(message);
        }
    )
}

// promise chaining

// in chaining we chain the then or catch function with one other.
// in this case the first always return a new promise for which then and catch are present
var askmon = function(){
    willIgetphone
    .then(showOff)
    .then( function(fullfilled){
        console.log(fullfilled);
    })
    .catch( function(error){
        console.log(error)
    })
}

askmon();


// promise use with fs modeule
function readFile(filepath, enc){
    return new Promise( function(fullfill, reject){
        fs.readFile(filepath, enc, function(err, res){
            if(err) reject(err)
            else fullfill(res);
        })
    })
}

// normal readFile
function readFile(filename, callback){
    fs.readFile(filename, enc, function(err, res){
        if(err) return callback(err)
        return callback(null, res);
    })
}

// for error handling without promise

function readFile(filename, callback){
    fs.readFile(filename, enc, function(err, res){
        if(err) return callback(err);
        try{
            res = JSON.parse(res)
        }catch(ex){
            return callback(err)
        }

        return callback(null, res);
    })
}

// In order to use a promise, we must somehow be able to wait for it to be fulfilled or rejected. The way to do this is using promise.done

function readJSON(filepath, enc){
    return new Promise( function(resolve, reject){
        readFile(ilename, enc).done( function(res){
            try{
                return resolve(res)
            } catch(ex){
                reject(ex)
            }
        }, reject)
    })
}