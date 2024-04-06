import { Component } from 'react'
import './style.css'
export class Clock extends Component {
    state = {
        time: ''
    }
    
    passZero(value) {
        return value < 10 ? '0' + value : value
    }
    
    getCurrentTime() {
        const { format = '24', timezone = '+3' } = this.props

        const date = new Date()

        const utc = date.getTime() + (date.getTimezoneOffset() * 60000)

        const localTime = new Date(utc + (3600000 * timezone))

        let hours = localTime.getHours()
        let minutes = localTime.getMinutes()
        let seconds = localTime.getSeconds()

        if (format === '12') {
            hours = hours % 12
            return `${this.passZero(hours)}:${this.passZero(minutes)}:${this.passZero(seconds)}`
        } else {
            return `${this.passZero(hours)}:${this.passZero(minutes)}:${this.passZero(seconds)}`
        }
    }

    componentDidMount() {
        this.setState({ time: this.getCurrentTime() })
    }

    render() {
        return (
            <div className='clock'>
                <div>{this.state.time}</div>
           </div>
        )
    }
}
export default Clock