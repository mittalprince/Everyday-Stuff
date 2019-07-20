import { Component, OnInit } from '@angular/core'
import * as Moment from 'moment'
import { extendMoment } from 'moment-range'

const moment = extendMoment(Moment)

@Component({
    selector: 'app-calender',
    templateUrl: './calender.component.html',
    styleUrls: ['./calender.component.css']
})

export class CalenderComponent implements OnInit{

    weekDays: any = [
        'Sunday',
        'Monday',
        'Tuesday',
        'Wednesday',
        'Thursday',
        'Friday',
        'Saturday'
    ] 
    calender: any ={
        weeks: [],
        current_month_string: moment().format('MMMM'), // Get Current Month Name
        current_month_number: moment().month() + 1, // Get Current Month Number
        current_date: moment().startOf('month'), // Get start date of current month
        current_year: moment().year(), // Get current year
        current_days_count: moment().daysInMonth(), // Get no of days of current month
        first_day_number: moment().startOf('month').weekday() // Gets the day of the week

    } 
    constructor(){
        console.log(this.calender)
        this.createCalenderFirstWeek()
    }


    createCalenderFirstWeek(){
        let temp_first_week = []
        for(let i = 0; i<this.calender.first_day_number; i++){
            temp_first_week.push(null)
        }
        let temp_length = this.calender.first_day_number
        for(let j=1; j<=(7 - temp_length); j++){
            temp_first_week.push(j)
        }
        this.calender.weeks[0] = temp_first_week
        this.createOtherWeeks()
    }

    createOtherWeeks(){
        let start_point = this.calender.weeks[0][this.calender.weeks[0].length -1] + 1
        this.calender.weeks[1] = []
        let week_no = 1
        for(let k=start_point; k<=this.calender.current_days_count; k++){
            if(this.calender.weeks[week_no].length < 7){
                this.calender.weeks[week_no].push(k)
            }
            else{
                week_no += 1
                this.calender.weeks[week_no] = [k]
            }
        }

        var index_of_last_week = this.calender.weeks.length - 1
        var length_of_last_week = this.calender.weeks[index_of_last_week].length 
        for(let i=length_of_last_week; i<7; i++){
            this.calender.weeks[index_of_last_week].push(null)
        }
    }

    dayActiveClassCheck(day){
        let current_year = moment().year()
        let current_month = moment().month() + 1

        if(current_year == this.calender.current_year){
            if(current_month == this.calender.current_month_number){
                if(moment().date() > day){
                    return false
                }
                else{
                    return true
                }
            }
            else if (current_month > this.calender.current_month_number) {
                return false
            } 
            else {
                return true
            }
        }
        else if (current_year > this.calender.current_year) {
            return false
        } 
        else {
            return true
        }
    }

    todayClassCheck(day){
        if(moment().year() == this.calender.current_year){
            if((moment().month()+1) == this.calender.current_month_number){
                if(moment().date() == day){
                    return true
                }
                else{
                    return false
                }
            }
            else{
                return false
            }
        }
    }

    currentMonthChange(operation) {
        var current_date = moment(this.calender.current_date)
        if (operation == 'previous') {
            this.calender.current_date = current_date.subtract(1, 'month')
        } else if (operation == 'next') {
            this.calender.current_date = current_date.add(1, 'month')
        }
        console.log(current_date)
        this.calender.current_month_string = current_date.format('MMMM')
        this.calender.current_year = current_date.year()
        this.calender.current_days_count = current_date.daysInMonth()
        this.calender.first_day_number = current_date.startOf('month').weekday()
        this.calender.current_month_number = current_date.month() + 1
        this.calender.weeks = []
        this.createCalenderFirstWeek()
    }

    ngOnInit(){}
}