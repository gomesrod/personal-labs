/**
 * inter process Communication - renderer-side
 */

const { ipcRenderer } = require('electron')

export default {
    writeToFile: function(contents) {
        ipcRenderer.sendSync('write-to-file', 'ping')
    }
}
