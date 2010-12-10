plugin().connect("192.168.250.2");
plugin().getDeviceInfo();

addEvent(plugin(), 'addprivbook', function(state, process){
    logCallback("add", state, process);
});

addEvent(plugin(), 'replaceprivbook', function(state, process){
    logCallback("replace", state, process);
});

addEvent(plugin(), 'fetchprivbook', function(state, process){
    logCallback("fetch", state, process);
});

path = "/home/quake/Desktop/CPP/test/test.snb";
plugin().addPrivBook(path);

function logCallback(tag, state, process) {
    if(state == 0) {
        console.log(tag + " : " + process);
    }else if (state = 1) {
        console.log(tag + " : done");
    }else{
        console.log(tag + " : error");
    }
}

books = plugin().getPrivBookInfos();
books.pop();

path = "/home/quake/Desktop/CPP/test/test.snb";

plugin().replacePrivBook("gchgxw3z082cvpz.snb", path);


plugin().fetchPrivBook("ugun52h2ln7dmhx.snb", "/tmp");


