<HTML>↲
    <HEAD>↲
        <TITLE>↲
            test-dbs php↲                                                                                                       
        </TITLE>↲
    </HEAD>↲
    <BODY>↲
        <TABLE border="1">↲
<?php↲
    $link = "";↲
    try{↲
        $link = mysqli_connect('localhost', 'BK19170', 'BK19170', 'BK19170');↲
        mysqli_set_charset($link, 'utf8');↲
    }↲
    catch(Exception $e) {↲
        echo $e -> getMessage();↲
    }↲
    if(mysqli_connect_errno()) { die("DB failure");}↲
    ↲
    $qs = "SELECT id, num From test";↲
    ↲
    if ($res = mysqli_query($link, $qs)){↲
        $element_id = "<th>id</th>";↲
        $element_num = "<th>num</th>";↲
        foreach($res as $row) {↲
            $element_id  = $element_id  . "<td>" . $row["id"] . "</td>";↲
            $element_num = $element_num . "<td>" . $row["num"] . "</td>";↲
        }↲
        echo("<tr>" . $element_id  . "</tr>");↲
        echo("<tr>" . $element_num . "</tr>");↲
    }↲
↲
    mysqli_close($link);↲
?>↲
↲
        </TABLE>↲
    </BODY>↲
</HTML>↲
                                                                                                                                
