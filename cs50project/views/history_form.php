<!-- create table -->
<table class="table table-striped" style="width:100%; text-align: left"> 
    <thead>
        <tr>
            <th>Source Text</th
            ><th>Translated From</th>
            <th>Translated To</th>
            <th>Google's Translation</th>
            <th>Microsoft's Translation</th>
        </tr>
    </thead>
    <tbody>
    <!-- create row for each field -->
    <?php foreach($positions as $position): ?>
        </tr>
        <tr>
            <td><?= $position["sourcetext"] ?></td>
            <td><?= $position["from_lang"] ?></td>
            <td><?= $position["to_lang"] ?></td>
            <td><?= $position["google"] ?></td>
            <td><?= $position["microsoft"] ?></td>
        </tr>
    <?php endforeach ?>
    </tbody> 
</table>