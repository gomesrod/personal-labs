import React from 'react';
import CommService from './comm-renderer'

class MyCounter extends React.Component {

    constructor() {
        super()
        this.state = { items: [], current: "" }

        this.onChangeCurrent = this.onChangeCurrent.bind(this)
        this.addItem = this.addItem.bind(this)
        this.saveList = this.saveList.bind(this)
    }

    onChangeCurrent(evt) {
        const newVal = evt.target.value
        this.setState({ current: newVal })
    }

    addItem() {
        const items = this.state.items
        const currentItem = this.state.current

        if (currentItem.trim() !== "") {
            this.setState({
                items: [...items, currentItem],
                current: ""
            })
        }
    }

    saveList() {
        const items = this.state.items
        const savedPath = CommService.writeToFile(items)

        let myNotification = new Notification('List saved', {
            body: `List saved to file: ${savedPath}`
        })
    }

    render() {
        return <div>
            <input type="text" value={this.state.current} onChange={this.onChangeCurrent}></input>
            <button onClick={this.addItem}>Add</button>

            <ul>
                {this.state.items.map((item, idx) => <li key={idx}>{item}</li>)}
            </ul>

            {this.state.items
                ? <button onClick={this.saveList}>Save list to file</button>
                : null}
        </div>
    }
}

export default MyCounter