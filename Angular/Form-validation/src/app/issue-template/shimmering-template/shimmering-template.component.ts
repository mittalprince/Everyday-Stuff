import { Component, OnInit } from '@angular/core'

@Component({
    selector: 'app-shimmering-template',
    templateUrl: './shimmering-template.component.html',
    styleUrls: ['./shimmering-template.component.css']
})

export class ShimmerTemplateComponent implements OnInit{

    toggleDetails: boolean = false
    assign: Boolean = false

    background: any = [
        '#39f', '#1e87f0', '#1e87f0', '#f0506e', '#5af050', '#32d296', '#d23250', '#d2a8329c', '#512DA8'
    ]
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
        let randomSVG = this.background[Math.floor(Math.random() * this.background.length)];
        // console.log(randomSVG)
        let style = {
            'background': `${randomSVG}`
        }

        return style
    }
}