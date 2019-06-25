/**
 * inter process Communication - renderer-side
 */

const { ipcRenderer } = require('electron')

export default {
    writeToFile: function(contents) {
        return ipcRenderer.sendSync('write-to-file', contents)
    }
}
