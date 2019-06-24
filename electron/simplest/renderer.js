console.log("RUNNING IN RENDERER PROCESS")

const output = document.getElementById("outputText")

document.onkeypress = ev => {
    console.log("Key pressed", ev)
    output.innerHTML = "Your key is: " + ev.key
}
