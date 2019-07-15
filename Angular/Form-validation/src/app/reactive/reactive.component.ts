import { Component, OnInit } from '@angular/core'
import { FormControl, FormGroup, FormBuilder, Validators } from '@angular/forms'
import { forbiddenNameValidator } from './../partials/validators/forbidden-name-validator.directive'
import { MustMatch } from './../partials/validators/equalTo-validator.directive'
@Component({
    selector: 'reactive-app',
    templateUrl: './reactive.component.html',
    styleUrls: ['./reactive.component.css']
})

export class reactiveComponent implements OnInit{

    iconFlip1 = true;
    iconFlip2 = true;
    genders: any = ['Male', 'Female', 'Others']
    constructor(private fb: FormBuilder){}

    ngOnInit(){}
    
    // registrationForm = new FormGroup({
    //     firstName: new FormControl(''),
    //     lastName: new FormControl('')
    // })

    registrationForm = this.fb.group({
        firstName: ['', [Validators.required]],
        lastName: ['', [Validators.required]],
        username: ['', [Validators.required, Validators.minLength(5), forbiddenNameValidator('admin')]],
        email: ['', [Validators.required, Validators.email]],
        phone: ['', [Validators.required]],
        gender: ['Male', Validators.required],
        password: ['', [Validators.required, Validators.minLength(8), forbiddenNameValidator('password')]],
        cpassword: ['', [Validators.required, MustMatch('password')]]
    })

    changePasswordType(){
        let input = document.getElementById('password')
        if(this.iconFlip1){
            input.setAttribute('type', 'text')
            this.iconFlip1 = !this.iconFlip1
        }
        else{
            input.setAttribute('type', 'password')
            this.iconFlip1 = !this.iconFlip1
        }    
    }

    changeCPasswordType(){
        let input = document.getElementById('cpassword')
        if(this.iconFlip2){
            input.setAttribute('type', 'text')
            this.iconFlip2 = !this.iconFlip2
        }
        else{
            input.setAttribute('type', 'password')
            this.iconFlip2 = !this.iconFlip2
        }    
    }
}