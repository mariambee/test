<!-- create table -->
<table class="table table-striped" style="width:100%; text-align: left"> 
    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>
    <tbody>
    <!-- create row for each trasaction -->
    <?php foreach($positions as $position): ?>
        </tr>
        <tr>
            <td><?= $position["transaction"] ?></td>
            <td><?= $position["date"] ?></td>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td>$<?= $position["price"] ?></td>
        </tr>
    <?php endforeach ?>
    </tbody> 
</table>