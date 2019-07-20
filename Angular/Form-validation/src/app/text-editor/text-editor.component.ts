import { Component, OnInit } from '@angular/core'
import * as Quill from 'quill'

@Component({
    selector: 'app-editor',
    templateUrl: './text-editor.component.html',
    styleUrls: ['./text-editor.component.css']
})

export class TextEditorComponent implements OnInit{

    quill;
    toolbarOptions: any = {
        container: [
            [{ 'size': ['small', false, 'large', 'huge'] }],
            [{ 'header': [1, 2, 3, 4, 5, 6, false] }],

            ['bold', 'italic', 'underline', 'strike', 'link'],
            ['blockquote', 'code-block'],

            [{ 'list': 'ordered' }, { 'list': 'bullet' }],
            [{ 'align': [] }],
            [{ 'indent': '-1' }, { 'indent': '+1' }],
            [{ 'direction': 'rtl' }],

            [{ 'script': 'sub' }, { 'script': 'super' }],

            [{ 'color': [] }, { 'background': [] }],
            [{ 'font': [] }],

            ['clean'],
            ['image']
        ],
        handlers: {}
    };
    htmlData = '<p><br></p>';

    constructor(){
    }
    ngOnInit(){

        // @Custom Image Upload Handler Function for Quill

        // this.toolbarOptions.handlers.image = () => {
        //     var self = this
        //     if (self.image_upload_counter > 0) {
        //         self.image_upload_counter -= 1
        //         const input = document.createElement('input');
        //         const formData = new FormData();

        //         input.setAttribute('type', 'file');
        //         input.setAttribute('accept', 'image/*');
        //         input.click();
        //         input.onchange = function () {
        //             let url = ''
        //             const file = input.files[0]
        //             formData.append('images', file);

        //             const range = self.quill.getSelection(true);
        //             self.quill.insertEmbed(range.index, 'image', 'Image Uplading, please wait...');
        //             self.quill.setSelection(range.index + 1);
        //             console.log(formData, self)
        //             self.coworkService.guidelineImages(formData).subscribe(resp => {
        //                 console.log(resp)
        //                 self.quill.deleteText(range.index, 1);
        //                 self.quill.insertEmbed(range.index, 'image', resp.result)
        //             }, err => {
        //                 console.log(err)
        //                 if (self.image_upload_counter < 2) {
        //                     self.image_upload_counter += 1
        //                 }
        //             })
        //         }
        //     }
        //     else {
        //         alert('Max 2 images allowed per guideline')
        //     }
        // }

        this.createEditorInstance()
    }

    createEditorInstance() {
        if (document.getElementById('editor')) {
            this.quill = new Quill('#editor', {
                modules: {
                    toolbar: this.toolbarOptions
                },
                theme: 'snow',
                placeholder: 'Compose an epic...',
                readOnly: false,
            })
        }
    }

    getEditorContent(){
        this.htmlData =this.quill.root.innerHTML
    }
}   