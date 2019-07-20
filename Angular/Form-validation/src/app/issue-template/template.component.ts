import { Component, OnInit } from '@angular/core'

@Component({
    selector: 'app-issue-template',
    templateUrl: './template.component.html',
    styleUrls: ['./template.component.css']
})

export class TemplateComponent implements OnInit{

    toggleDetails: boolean = false
    assign: Boolean = false
    
    constructor(){}

    ngOnInit(){
        this.setImage()
    }

    toggle(){
        if (this.toggleDetails == false) {
            this.toggleDetails = true
            this.cancelUpdateAssign()
        } else {
            return 0
        }
    }

    closeDetails() {
        if (this.toggleDetails == true) {
            this.toggleDetails = false
        } else {
            return 0
        }
    }

    cancelUpdateAssign(){
        if(this.assign == true){
            this.assign = false
        }
        else{
            return 0
        }
    }

    updateAssign(){
        if(this.assign == false){
            this.assign = true
            this.closeDetails()
        }
        else{
            return 0
        }
    }

    setImage(){
        // if(document.getElementById('profile')){
        //     document.getElementById('profile').innerHTML = 'PM'
        // }
        // document.getElementById('profile').innerHTML = 'PM'

        return 'PM'
    }

    setBackground(){
        var color = Math.floor(0x1000000 * Math.random()).toString(16);
        let randomBg =  '#' + ('000000' + color).slice(-6);
        let style = {
            'background': `${randomBg}`
        }

        return style
    }
}