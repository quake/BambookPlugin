plugin().connect("192.168.250.2");
plugin().getPrivBookInfos();
plugin().getDeviceInfo();

addEvent(plugin(), 'SendSnbToBambook', function(state, process){
    console.log(process);
});

plugin().sendSnbToBambook("/home/quake/Desktop/bambook_sdk/CPP/test/test.snb");
