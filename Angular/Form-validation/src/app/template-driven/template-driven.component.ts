import { Component, OnInit } from '@angular/core';

@Component({
    selector:'template-driven-app',
    templateUrl: './template-driven.component.html',
    styleUrls: ['./template-driven.component.css']
})

export class templateDrivenComponent implements OnInit{

    data: any = {
        gender: ''
    }
    iconFlip1 = true
    iconFlip2 = true
    constructor(){}

    ngOnInit(){}

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