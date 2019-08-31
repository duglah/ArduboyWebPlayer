function makeAlert(text) {
    //alert(text);
    console.log(text)
}

if (typeof mergeInto !== 'undefined') mergeInto(LibraryManager.library, {
    jsBegin: function() {
        console.log("jsBegin")
    },
    jsSetFrameRate: function(rate) {
        console.log("setFramerate to " + rate)
    },
    jsNextFrame: function() {
        console.log("jsNextFrame")
        return true
    },
    jsSetCursor: function(x,y) {
        console.log("jsSetCursor " + x + " " + y)
    },
    jsDisplay: function (pointer) {
        console.log("jsDisplay")
        const ctx = document.getElementById('c').getContext('2d');
        const data = new Uint8ClampedArray(Module.HEAP32.buffer, pointer, width * height * 4);
        const img = new ImageData(data, width, height);
        ctx.putImageData(img, 0, 0);
    },
    jsPrint: function(text) {
        text = UTF8ToString(text, 20);
        console.log("jsPrint: " + text);
    },
    jsClear: function() {
        console.log("jsClear")
    }
});