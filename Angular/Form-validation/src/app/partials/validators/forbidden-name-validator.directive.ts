import { Validator, NG_VALIDATORS, AbstractControl, ValidatorFn} from '@angular/forms'
import { Input, Directive } from '@angular/core'

@Directive({
    selector: '[appForbiddenName]',
    providers: [{
        provide: NG_VALIDATORS,
        useExisting: ForbiddenValidatorDirective,
        multi: true
    }]
})

export class ForbiddenValidatorDirective implements Validator{
    @Input('appForbiddenName') forbiddenName:  string;
    validate(control: AbstractControl): { [key: string]: any} | null {
        return this.forbiddenName ? forbiddenNameValidator(this.forbiddenName)(control) : null

    }
}

export function forbiddenNameValidator(nameRe: string): ValidatorFn{
    return (control: AbstractControl): { [key: string]: any } | null => {
        const value = control.value
        if(!value){
            return null
        }
        else if (nameRe === (control.value).toLowerCase()){
            return {'forbiddenName': true}
        }
        return null;
    }
}