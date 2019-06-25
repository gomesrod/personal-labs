/**
 * inter process Communication - main-side
 */

const os = require('os')
const path = require('path')
const fs = require('fs')

const { ipcMain } = require('electron')

ipcMain.on('write-to-file', (event, obj) => {
    console.log("Main received write-to-file message", obj)

    const filePath = writeToFile(JSON.stringify(obj))

    event.returnValue = filePath
})

function writeToFile(contents) {
    const filePath = path.join(os.homedir(), "my-reactapp-data.json")

    fs.writeFileSync(filePath, contents);
}