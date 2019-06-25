/**
 * inter process Communication - renderer-side
 */

const electron = require('electron')

const ipcRenderer = electron.ipcRenderer

export default {
    writeToFile: function(contents) {
        const savedPath = ipcRenderer.sendSync('write-to-file', contents)
        console.log("write-to-file call returned: ", savedPath)
        return savedPath
    }
}
