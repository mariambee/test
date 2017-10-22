<!-- create table -->
<table class="table table-striped" style="width:100%; text-align: left"> 
    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>Total</th>
        </tr>
    </thead>
    <tbody>
    <!-- create row for each stock -->
    <?php foreach($positions as $position): ?>
        </tr>
        <tr>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["name"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td>$<?= number_format($position["price"], 2) ?></td>
            <td>$<?= number_format($position["Total"], 2) ?></td>
        </tr>
    <?php endforeach ?>
    <!-- place cash -->
    <tr>
        <td>CASH</td>
        <td></td><td></td><td></td>
        <td>$<?=number_format($users[0]["cash"], 2)?></td>
    </tr>
    </tbody> 
</table>