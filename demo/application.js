var bb = document.getElementById('bambookplugin');

function addEvent(name, func) {
    if (window.addEventListener) {
        bb.addEventListener(name, func, false);
    } else {
        bb.attachEvent("on"+name, func);
    }
}

addEvent('privbooktrans', function(state, progress, userdata){
    $("#progress").val(progress);
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

    $("#btn_upload").click(function() {
        bb.addPrivBook($(this).next().val());
        return false;
    });

    $("#bambook_books a.export").live('click', function() {
        bb.fetchPrivBook($(this).parent().attr("guid"), $("#tmp_folder").val());
        return false;
    });

    $("#bambook_books a.delete").live('click', function() {
        if(confirm("你确定要删除这本书吗？")) {
            bb.deletePrivBook($(this).parent().attr("guid"));
            return false;
        }
    });
});

$(window).unload(function() {
    bb.disconnect();
});
