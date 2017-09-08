var downloadinfo = null;


function mmsv_checkAll(bcall) {
    var bcheck;
    var form = document[Name_Transe_Form];

    if (!bcall) {
        if (!form.chkall.checked) {
            bcheck = false;
        } else {
            bcheck = true;
        }
    } else {
        bcheck = true;
        form.chkall.checked = bcheck;
    }

    // 폴더 체크
    var chkBox = form.elements['mmsv_trans_folder'];
    var chkLen = chkBox.length;

    if (!chkLen) {
        chkBox.checked = bcheck;
    } else {
        for (i = 0; i < chkLen; i++) {
            chkBox[i].checked = bcheck;
        }
    }

    // 파일 체크
    var chkBox = form.elements['mmsv_trans_file'];
    var chkLen = chkBox.length;

    if (!chkLen) {
        chkBox.checked = bcheck;
    } else {
        for (i = 0; i < chkLen; i++) {
            chkBox[i].checked = bcheck;
        }
    }

    //mmsv_checkCountSet();
}

function mmsvView() {
}

function mmsv_downloadFile(cooperation_info) {

    var form = document[Name_Transe_Form];

    if (mmsv_isChecked()) {
        mmsv_Trans_Make();
        //mureka post값 만들기
        if (cooperation_info) form.cooperation_info.value = cooperation_info;
        form.pg_mode.value = "mmsv_down";
        form.submit();
    } else {
        alert("다운 받으실 파일을 선택하세요.\n업로드가 완료 되지 않은 파일은 선택하셔도 다운 받으실 수 없습니다.");
        return false;
    }
}

function mmsv_Trans_Make() {

    // 전체 선택
    var arr_files_list = new Array();
    var arr_folders_list = new Array();

    var form = document[Name_Transe_Form];

    var chkBox_files = form.elements['mmsv_trans_file'];
    var chkLen_files = chkBox_files.length;

    var chkBox_folders = form.elements['mmsv_trans_folder'];
    var chkLen_folders = chkBox_folders.length;

    var index = 0;

    for (i = 0; i < chkLen_files; i++) {
        if (chkBox_files[i].checked && chkBox_files[i].value != "") {
            arr_files_list[index] = chkBox_files[i].value;
            index++;
        }
    }

    index = 0;

    for (i = 0; i < chkLen_folders; i++) {
        if (chkBox_folders[i].checked && chkBox_folders[i].value != "") {
            arr_folders_list[index] = chkBox_folders[i].value;
            index++;
        }
    }

    form.mmsv_files.value = "";
    form.mmsv_folders.value = "";

    form.mmsv_files.value = arr_files_list.join("<>");
    form.mmsv_folders.value = arr_folders_list.join("<>");
}

function mmsv_isChecked() {

    var form = document[Name_Transe_Form];
    var chkBox = form.elements['mmsv_trans_file'];
    var chkLen = chkBox.length;

    // 선택된 파일이 있는지 체크
    if (!chkLen) {
        if (chkBox.checked) return true;
        else return false;
    } else {
        for (i = 0; i < chkLen; i++) {
            if (chkBox[i].checked) return true;
        }
        return false;
    }
}


function mmsv_bbs_download_init() {
    downloadinfo = {};
    downloadinfo.fileinfo = [];
    return downloadinfo;
}

function mmsv_bbs_download_item_dev(item, path, userid, fileno, hash, downchk, mureka_log, bbs_ho, cooperation_idx, price, uploader, chkadmin, title, code_cate2, content_id) {
    downloadinfo.fileinfo.push(MakeDownloadInfoJsonObject(item, path, userid, fileno, hash, downchk, mureka_log, bbs_ho, cooperation_idx, price, uploader, chkadmin, title, code_cate2, content_id));
    return downloadinfo;
}

function mmsv_bbs_download_end(userid, userpw, datas) {
    try {
        downloadinfo.code = "REQ_DOWNLOAD";
        downloadinfo.userid = userid;
        downloadinfo.userpw = userpw;
        downloadinfo.datas = datas;
        WebhardCtrl.FireDownload(JSON.stringify(downloadinfo)) ;

    } catch (exception) {
        alert('ERROR exception : ' + exception);

    }
}

function checkConnect() {
    return ;
}

// 펑션
function MakeDownloadInfoJsonObject(item, path, userid, fileno, hash, downchk, mureka_log, bbs_ho, cooperation_idx, price, uploader, chkadmin, title, code_cate2, content_id) {
    var obj = {};
    obj.item = item;
    obj.path = path;
    obj.userid = userid;
    obj.fileno = fileno;
    obj.hash = hash;
    obj.downchk = downchk;
    obj.mureka_log = mureka_log;
    obj.bbs_ho = bbs_ho;
    obj.cooperation_idx = cooperation_idx;
    obj.price = price;
    obj.uploader = uploader;
    obj.chkadmin = chkadmin;
    obj.title = title;
    obj.code_cate2 = code_cate2;
    obj.content_id = content_id;

    return obj;
}


function GetSeial() {
    return  WebhardCtrl.GetSeial() ;
}


