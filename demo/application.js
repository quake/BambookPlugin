var bb = document.getElementById('bambookplugin');

function addEvent(name, func) {
    if (window.addEventListener) {
        bb.addEventListener(name, func, false);
    } else {
        bb.attachEvent("on"+name, func);
    }
}

addEvent('privbooktrans', function(state, progress, userdata){
    console.log(state + " | " + progress + " | " + userdata);
});

addEvent('privbooktransbyrawdata', function(data){
    console.log("upload rawdata to server");
    $.post("/welcome/test", {
        data: data
    });
});

$(function() {            
    $("#btn_connect").click(function() {
        var result = bb.connect($(this).next().val());
        if(result == 0) {
            alert("连接成功");
        }else{
            alert("连接错误: " + result);
        }
    });

    var book_markup = "<tr><td>${name}</td><td>${author}</td><td guid='${guid}'><a href='#' class='export'>导出</a> <a href='#' class='delete'>删除</a></td></tr>";
    $.template("book_template", book_markup);

    $("#btn_list").click(function() {
        var books = bb.getPrivBookInfos();
        $("#bambook_books").empty();
        $.tmpl("book_template", books).appendTo("#bambook_books");
    });

    $("#bambook_books a.export").live('click', function() {
        bb.fetchPrivBookByRawData($(this).parent().attr("guid"));
        return false;
    });

    $("#bambook_books a.delete").live('click', function() {
        if(confirm("你确定要删除这本书吗？")) {
            bb.deletePrivBook($(this).parent().attr("guid"));
            return false;
        }
    });

    $("#btn_download").click(function() {
        $.get($(this).next().val(), function(data){
            bb.addPrivBookByRawData("temp.snb", data);
        });
        return false;
    });
});

$(window).unload(function() {
    bb.disconnect();
});
