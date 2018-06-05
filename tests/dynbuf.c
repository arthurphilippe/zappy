/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** dynbuf
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "dynbuf.h"

Test(Dynbuf, create)
{
	dynbuf_t *buf = dynbuf_create();

	cr_assert(buf);
	cr_assert_eq(buf->b_allotted, BUF_SIZE);
	cr_assert_str_empty(buf->b_data);
	cr_assert_eq(buf->b_lengh, 0);
	dynbuf_delete(buf);
}

Test(Dynbuf, append_few)
{
	dynbuf_t *buf = dynbuf_create();

	cr_assert(buf);
	cr_assert_eq(buf->b_allotted, BUF_SIZE);
	cr_assert_eq(buf->b_lengh, 0);
	dynbuf_append_str(buf, "salut");
	cr_assert_str_eq(buf->b_data, "salut");
	dynbuf_append_str(buf, "salut");
	cr_assert_str_eq(buf->b_data, "salut""salut");
	dynbuf_append_str(buf, "salut");
	cr_assert_str_eq(buf->b_data, "salut""salut""salut");
	dynbuf_delete(buf);
}

Test(Dynbuf, append_loads)
{
	dynbuf_t *buf = dynbuf_create();

	cr_assert(buf);
	cr_assert_eq(buf->b_allotted, BUF_SIZE);
	cr_assert_eq(buf->b_lengh, 0);
	dynbuf_append_str(buf, "Incidunt inventore tempora similique ab tempore blanditiis. Commodi sit eveniet eius sequi. Repellendus architecto eos aut blanditiis in. Atque enim voluptate quam quis quas excepturi dignissimos. Error rerum doloribus quia eum totam consequuntur. Qui provident recusandae nostrum. Vel ea nostrum accusantium qui quis. Ullam voluptatibus et veniam. Ullam delectus perferendis cum temporibus non tempora et. Eveniet velit dolores commodi rerum asperiores maxime. Repellat autem dolorum corporis dignissimos numquam ut voluptas. Temporibus aut autem qui repellendus ut nemo dignissimos a. Suscipit nulla ad aut doloribus est sunt rerum quo. Molestiae voluptas expedita officiis ut dolorum molestiae officiis molestiae. In autem ut et consequuntur est autem. Cumque id enim ut dolor est. Ut et id aut vel officiis ea. Eveniet voluptatem minima laboriosam. Laudantium sed libero et. Ea qui nihil et autem quis explicabo minima. Modi ducimus molestiae nesciunt sit ut exercitationem. A vero est quisquam eos. Tempora nesciunt consequuntur velit quis molestiae et. Omnis aut necessitatibus dolor non nihil corrupti.");
	cr_assert_eq(buf->b_allotted, 1536, "alloted is %d instead of 1536", buf->b_allotted);
	cr_assert_eq(buf->b_lengh, 1109);
	dynbuf_append_str(buf, "salut");
	cr_assert_str_eq(buf->b_data, "Incidunt inventore tempora similique ab tempore blanditiis. Commodi sit eveniet eius sequi. Repellendus architecto eos aut blanditiis in. Atque enim voluptate quam quis quas excepturi dignissimos. Error rerum doloribus quia eum totam consequuntur. Qui provident recusandae nostrum. Vel ea nostrum accusantium qui quis. Ullam voluptatibus et veniam. Ullam delectus perferendis cum temporibus non tempora et. Eveniet velit dolores commodi rerum asperiores maxime. Repellat autem dolorum corporis dignissimos numquam ut voluptas. Temporibus aut autem qui repellendus ut nemo dignissimos a. Suscipit nulla ad aut doloribus est sunt rerum quo. Molestiae voluptas expedita officiis ut dolorum molestiae officiis molestiae. In autem ut et consequuntur est autem. Cumque id enim ut dolor est. Ut et id aut vel officiis ea. Eveniet voluptatem minima laboriosam. Laudantium sed libero et. Ea qui nihil et autem quis explicabo minima. Modi ducimus molestiae nesciunt sit ut exercitationem. A vero est quisquam eos. Tempora nesciunt consequuntur velit quis molestiae et. Omnis aut necessitatibus dolor non nihil corrupti.""salut");
	cr_assert_eq(buf->b_allotted, 1536, "alloted is %d instead of 1536", buf->b_allotted);
	dynbuf_delete(buf);
}
